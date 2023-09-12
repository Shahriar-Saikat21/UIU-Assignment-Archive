//external imports
const path = require('path');

//internal imports
const Memory = require('../model/memoryModel.js'); //memory model

const addMemoryControll = {};

//addMemory Page
addMemoryControll.addMemoryPage = (req, res) => {
    res.sendFile(path.join(path.join(__dirname,'..'),'..','frontend/addMemory.html'));
};

//Post memory
addMemoryControll.addMemory = async(req, res) => {
    try {
        const newMomory = new Memory({
            title: req.body.title,
            story: req.body.story,
            image: {
                data : req.file.buffer,
                contentType : req.file.mimetype
            },
            user : req.id
        });
        await newMomory.save();
        res.redirect('/home');
    } catch (err) {
        res.send(err.message);
    }
    
};

module.exports = addMemoryControll;