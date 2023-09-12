//external imports
const path = require('path');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');

//internal imports
const User = require('../model/userModel'); //user model

const loginControl = {};

//login or Home page
loginControl.loginPage = (req, res) => {
    res.sendFile(path.join(path.join(__dirname,'..'),'..','frontend/login.html'));
}

//login user
loginControl.loginUser = async(req, res) => {
    try {
        const user = await User.findOne({ email: req.body.email });

        if (user && user._id) {
            const isValidPass = await bcrypt.compare(req.body.password, user.password);

            if (isValidPass) {
                const userObject = {
                    id: user._id,
                    userName: user.userName
                }

                //token generate
                const token = jwt.sign(userObject, process.env.JWT_SECRET, {
                    expiresIn: process.env.JWT_EXPIRES_IN
                });

                //cookie set
                res.cookie(process.env.COOKIE_NAME, token, {
                    maxAge: process.env.JWT_EXPIRES_IN,
                    httpOnly: true,
                    signed: true,
                    // secure: true //(for https)
                });

                res.status(500).json({message: "User Logged In Successfully",success:true});
            }else{
                res.status(200).json({message: "Invalid email or password",success:false});
            }
        }else{
            res.status(200).json({message: "Invalid email or password",success:false});
        }
    } catch (err) {
        res.status(200).json({message: err.message,success:false});
    }
    
};


//logout user
loginControl.logoutUser = (req, res) => {
    res.clearCookie(process.env.COOKIE_NAME);
    res.status(500).json({message: "User Logged Out Successfully",success:true});
};


module.exports = loginControl;