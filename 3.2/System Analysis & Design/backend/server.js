//external import
const express = require('express');
const cookieParser = require('cookie-parser');
const dotenv = require('dotenv').config();

//internal import
const connectDB = require('./config/db');  //database connection
const {notFoundHandler,errorHandler} = require('./middleware/errorHandle'); //error handle middleware
const loginRoute = require('./route/loginRoute.js'); //login page route
const signupRoute = require('./route/signupRoute'); //signup page route
const homeRoute = require('./route/homeRoute');//home page route
const addMemoryRoute = require('./route/addMemoryRoute');//add memory page route
const storyDetailRoute = require('./route/storyDetailRoute');//story detail page route
const deleteRoute = require('./route/deleteRoute');//delete memory route
const updateRoute = require('./route/updateRoute');//update memory route

//initialization
const app = express();

//external middleware
app.use(express.json());
app.use(cookieParser(process.env.COOKIE_SECRET));
app.use(express.static('frontend'));

//login or Home page & login user & log out from account
app.use(loginRoute);

//signup page & sign up user
app.use(signupRoute);

//user home page & show all memory
app.use(homeRoute);

//add memory page & add memory
app.use(addMemoryRoute);

//show memory detail page & show memory detail content
app.use(storyDetailRoute);

//update memory page, show data for update,update memory
app.use(updateRoute);

//delete memory
app.use(deleteRoute);

//Custom error handle
app.use(notFoundHandler);
app.use(errorHandler);

//server start
app.listen(process.env.port, async() => {
    await connectDB();
    console.log(`Server is running on port: ${process.env.port}`);
});