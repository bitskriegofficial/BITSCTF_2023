const express = require("express");
const app = express();
const geoip = require('geoip-country');
const path = require("path");

app.set("view engine", "ejs")
// app.use(express.static(path.join(__dirname,'static')))



app.get("/", (req, res) => {
    var text;
    console.log(req.headers);
	// //Print the value of header 'first_name'.
	// console.log((req.header('user-agent')));
	// console.log(typeof(req.header('user-agent')));


    if( (req.header('referer')) == undefined || !((req.header('referer')).startsWith("https://ctf.bitskrieg.org"))  ){
        console.log(" Make sure you came from the orignal website !! ");
        text = " Make sure you came from the orignal website !! ";
    }
    else if(req.header('date') != "26 Jan 2004"){
        console.log(" System Clock in inCorrect");
        text = "System Clock in inCorrect ";
    }
    else if(req.header('user-agent') != "Supreme"){
        console.log("Not a Supreme Browser");
        text = "Not a Supreme Browser";
    }
    else if(req.header('Authorization') != "BITSCTF{y0ur_4uth_t0k3n}"){
        console.log("Not Authorized");
        text = " Not Authorized go find authorization token ";
    }
    else if(req.header('x-forwarded-for') == undefined  || geoip.lookup(req.header('x-forwarded-for')).country != "UA"){
        console.log(" Not in Ukraine!!");
        text = "Not in Ukraine!!! ";
    }
    else{
        text = "BITSCTF{w3b_h3ad3r_g0d_8265} ";
    }


    // var geo = geoip.lookup(req.header('x-forwarded-for')).country;
    // console.log(geo);


	// res.sendFile('index.html');
    res.render('showme', {
        textchange: text
    })


});



app.listen(8989, () => {
  console.log("Application started and Listening on port 8989");
});