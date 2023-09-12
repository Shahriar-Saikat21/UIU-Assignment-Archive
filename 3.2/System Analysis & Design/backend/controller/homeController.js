//external imports
const path = require('path');
const jwt = require('jsonwebtoken');

//internal imports
const Memory = require('../model/memoryModel.js'); //memory model

const homeControl = {};

//user home page
homeControl.home = (req, res) => {
    res.sendFile(path.join(path.join(__dirname,'..'),'..','frontend/home.html'));
};


// show user detail in home page
homeControl.userDetail = async(req, res) => {
    try {
        const token = req.signedCookies[process.env.COOKIE_NAME];

        if (token) {
            const decoded = jwt.verify(token, process.env.JWT_SECRET);
            res.status(500).json({message: "User Found",success:true,user:decoded});
        }else{
            res.status(200).json({message: "User Not Found",success:false});
        }
    } catch (err) {
        res.status(200).json({message: err.message,success:false});
    }
};

//show memory list in user home page
homeControl.showMemory = async(req, res) => {
    try {
        const memories = await Memory.find({user:req.id});
        res.status(500).json({success:true,memories:memories});
    } catch (err) {
        res.status(200).json({message: err.message,success:false});
    }
};

module.exports = homeControl;