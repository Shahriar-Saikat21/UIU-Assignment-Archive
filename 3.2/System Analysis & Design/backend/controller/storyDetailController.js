//external imports
const path = require('path'); 

//internal imports
const Memory = require('../model/memoryModel.js'); //memory model


const storyDetailController = {};


//show memory detail page
storyDetailController.storyDetail = (req, res) => {
    res.sendFile(path.join(path.join(__dirname,'..'),'..','frontend/myStory.html'));
};

//show memory detail content on the page
storyDetailController.storyDetailContent =async(req, res) => {
    const value = req.query.id;
    try {
        const memories = await Memory.findOne({_id:value});
        res.status(500).json({success:true,memory:memories});
    } catch (err) {
        res.status(200).json({message: err.message,success:false});
    }
};

module.exports = storyDetailController;