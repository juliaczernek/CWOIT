let video; 
let bodyPose;
let poses = [];
let tiles = [];
let canvasHeight = 500;
let canvasWidth = 500;
let zonesX = 5;
let zonesY = 2;
let tileWidth = canvasWidth / zonesX;
let tileHeight = canvasHeight / zonesY;
let ledPins = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11];
let leds = [];

function generateTiles(){
    let indexLed = 0;
    for (let y = 1; y < canvasHeight; y += canvasHeight / zonesY){
        for (let x =1; x < canvasWidth; x += canvasWidth / zonesX){
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

    bodyPose.detectStart(video, function(results){
        // store the results in a global (poses) variable
        poses = results;
    })
        
    generateTiles();
    tiles.forEach(tile =>{
        fill(100);
        rect(tile.x, tile.y, tileWidth, tileHeight);
    });

    leds = new five.Leds(ledPins);
}



function draw() {

    image(video,0,0);

    line(100, 0, 100, 500);
    line(200, 0, 200, 500);
    line(300, 0, 300, 500);
    line(400, 0, 400, 500);
    line(0, 250, 500, 250)
    

    if(poses.length>0){
        let wristX = poses[0].right_wrist.x;
        let wristY = poses[0].right_wrist.y;

        tiles.forEach(tile => {
        if(wristX > tile.x && wristX < tile.x + tileWidth){
            if(wristY > tile.y && wristY < tile.y + tileHeight){
                if(!tile.currentlyOn){
                    console.log("You entered tile at position: ", tile.x, tile.y);
                    leds[tile.attachedLed].on();
                    setTimeout(() =>{
                        leds[tile.attachedLed].off();
                        tile.currentlyOn = false;
                    }, 3000);
                    tile.currentlyOn = true;
                }
            }
        }
    })
    
    }

    

// p5 funciton
function mousePressed(){
    console.log(poses);
}

}

            