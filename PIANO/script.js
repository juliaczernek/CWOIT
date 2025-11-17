let video;
let bodyPose;
let poses = [];
let button1;
let button2;
let button3;
let button4;
let button5;
let button6;


function preload() {
 bodyPose = ml5.bodyPose();
    loadBoard();
}


function setup(){
    createCanvas(500, 500).parent("sketch-container");
    frameRate(15); 
    video = createCapture(VIDEO);
    video.hide();

    bodyPose.detectStart(video, function(results){
        // store the results in a global (poses) variable
        poses = results;
    })
        
    button = new five.Button(8);
    button = new five.Button(9);
    button = new five.Button(10);
    button = new five.Button(11);
    button = new five.Button(12);
    button = new five.Button(13);

    button.on("press", function(){
    console.log( "Button pressed" );
    })
}


function draw(){
    image(video, 0, 0);

    if(poses.length > 0) {

    }

}