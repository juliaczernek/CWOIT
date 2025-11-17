let video; 
let bodyPose;
let poses = [];

let tiles = [];

let canvasWidth = 500;
let canvasHeight = 500;

let zonesX = 8;
let zonesY = 8;

let tileWidth = canvasWidth / zonesX;
let tileHeight = canvasHeight / zonesY;

let leds;




function generateTiles() {
    let indexLed = 0;
    for (let y = 1; y < canvasHeight; y += canvasHeight / zonesY) {             // we create 2 rows
        for (let x = 1; x < canvasWidth; x += canvasWidth / zonesX) {           // we create 5 columns for each row
            tiles.push({
                x: x, 
                y: y,
                currentlyOn: false, 
                attachedLed: indexLed
            });
            indexLed++;
        }
    }
}


function preload() {
    bodyPose = ml5.bodyPose();
    loadBoard();
}



function setup() {
    createCanvas(canvasWidth, canvasHeight).parent("sketch-container");
    frameRate(15); 
    video = createCapture(VIDEO);
    video.hide();

    generateTiles();
    tiles.forEach(tile => {
        fill(100);
        rect(tile.x, tile.y, tileWidth, tileHeight);
    });

    bodyPose.detectStart(video, function(results){
        // store the results in a global (poses) variable
        poses = results;
    })

    leds = new five.Led.Pixel({
        pin: 3,
        length: 64,
        controller: "FIRMATA"
    });
}


function draw() {

    image(video,0,0);

    if(poses.length>0){

        let wristX = poses[0].right_wrist.x;
        let wristY = poses[0].left_wrist.y;

        tiles.forEach(tile => {
            // we check on X axis
            if(wristX > tile.x && wristX < tile.x + tileWidth){
                // then we check on Y axis
                if(wristY > tile.y && wristY < tile.y + tileHeight){
                    // then we make we didn't already trigger this tile
                    if(!tile.currentlyOn){
                        // debug
                        console.log("You entered tile at position: ", tile.x, tile.y);

                        // turn on the attached led
                        leds.pixel(tile.attachedLed).color("#9a1616ff");

                        // set a timeout to turn off the led after 1 second
                        setTimeout(() => {   
                            // turn on the attached led for 1 second
                            leds.pixel(tile.attachedLed).off();                         

                            // then set back the tile to false after 1 second
                            tile.currentlyOn = false;
                        }, 1000);

                        // set the tile as currently on to avoid retriggering
                        tile.currentlyOn = true;
                    }
                }
            }
        });
    }
}

// p5 funciton
function mousePressed(){
    console.log(poses);
}



