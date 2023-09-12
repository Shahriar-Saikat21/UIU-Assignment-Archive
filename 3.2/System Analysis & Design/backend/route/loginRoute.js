//external imports
const express = require('express');

//internal imports
const loginRoute = express.Router();

const loginControll = require('../controller/loginController.js');

//login or Home page
loginRoute.get('/', loginControll.loginPage);

//login user
loginRoute.post('/login', loginControll.loginUser);

//logout user
loginRoute.get('/logout', loginControll.logoutUser);

module.exports = loginRoute;




