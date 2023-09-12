//external imports
const path = require('path');
const bcrypt = require('bcrypt');

//internal imports
const User = require('../model/userModel'); //user model


const signupControl = {};

//signup page
signupControl.signupPage = (req, res) => {
    res.sendFile(path.join(path.join(__dirname,'..'),'..','frontend/signup.html'));
}

//signup user
signupControl.signupUser = async(req, res) => {
    const hashedPassword = await bcrypt.hash(req.body.password, 10);
    const newUser = new User({
        userName: req.body.userName,
        email: req.body.email,
        password: hashedPassword
    });

    try {
        await newUser.save();
        res.status(500).json({message: "User Created Successfully", success:true});
    } catch (err) {
        res.status(200).json({message: err.message,success:false});
    }
};

module.exports = signupControl;