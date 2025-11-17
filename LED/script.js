let video; 
let bodyPose;
let poses = [];
let timer = false;

let ledRed;
let ledGreen;
let ledWhite;
let ledBlue;
let ledYellow;


let ledRed2;
let ledGreen2;
let ledWhite2;
let ledBlue2;
let ledYellow2;

function preload() {
    bodyPose = ml5.bodyPose();
    loadBoard();
}

function setup() {
    createCanvas(500, 500).parent("sketch-container");
    frameRate(15); 
    video = createCapture(VIDEO);
    video.hide();

    bodyPose.detectStart(video, function(results){
        // store the results in a global (poses) variable
        poses = results;
    })
        
    ledRed = new five.Led(8);
    ledGreen = new five.Led(10);
    ledWhite = new five.Led(12);
    ledBlue = new five.Led(9);
    ledYellow = new five.Led(11);


    ledRed2 = new five.Led(6);
    ledGreen2 = new five.Led(4);
    ledWhite2 = new five.Led(2);
    ledBlue2 = new five.Led(5);
    ledYellow2 = new five.Led(3);
}

function ledOff(){
    ledRed.off();
    ledGreen.off();
    ledWhite.off();
    ledBlue.off();
    ledYellow.off();
    ledRed2.off();
    ledGreen2.off();
    ledWhite2.off();
    ledBlue2.off();
    ledYellow2.off();
}


function draw() {

    image(video,0,0);

    line(100, 0, 100, 500);
    line(200, 0, 200, 500);
    line(300, 0, 300, 500);
    line(400, 0, 400, 500);
    line(0, 250, 500, 250)
    

    if(poses.length>0){
        timer = false;

        let wristX = poses[0].right_wrist.x;
        let wristY = poses[0].right_wrist.y;
        ledRed.off();
        ledGreen.off();
        ledWhite.off();
        ledBlue.off();
        ledYellow.off();
        ledRed2.off();
        ledGreen2.off();
        ledWhite2.off();
        ledBlue2.off();
        ledYellow2.off();

        if (wristX > 0 && wristX <100 && wristY> 0 && wristY<250){
            ledRed.on();
        }else if(wristX > 100 && wristX <200 && wristY >0 && wristY <250){
            ledBlue.on();
        }else if(wristX > 200 && wristX <300 && wristY >0 && wristY <250){
            ledGreen.on();
        }else if(wristX > 300 && wristX <400 && wristY >0 && wristY <250){
            ledYellow.on();
        }else if(wristX > 400 && wristX <500 && wristY >0 && wristY <250){
            ledWhite.on();
        }else if(wristX > 0 && wristX <100 && wristY >250 && wristY<500){
            ledRed2.on();
        }else if(wristX > 100 && wristX <200 && wristY >250 && wristY<500){
            ledBlue2.on();
        }else if(wristX > 200 && wristX <300 && wristY >250 && wristY<500){
            ledGreen2.on();
        }else if(wristX > 300 && wristX <400 && wristY >250 && wristY<500){
            ledYellow2.on();
        }else{
            ledWhite2.on();
        }
    }else if(!timer){
        timer = true;
        setTimeout(ledOff, 5000);
    }
}

// p5 funciton
function mousePressed(){
    console.log(poses);
}



            