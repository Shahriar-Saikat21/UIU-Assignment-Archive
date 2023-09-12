//external imports
const path = require('path');

//internal imports
const Memory = require('../model/memoryModel');

const updateController = {};

//show update page
updateController.updatePage = (req, res) => {
    res.sendFile(path.join(path.join(__dirname,'..'),'..','frontend/updateMemory.html'));
};

//show data for update page
updateController.updateData = async(req, res) => {
    const memID = req.query.id;
    try {
        const memory = await Memory.findOne({_id:memID});
        res.status(500).json({success:true,memory:memory});
    }catch(err){
        res.status(200).json({message: err.message,success:false});
    }
};

//update memory

updateController.updateMemory = async(req, res) => {
    const memID = req.query.id;
    try {
        await Memory.updateOne({_id:memID},{$set:{title:req.body.title,story:req.body.story}});
        res.status(500).json({message: "Memory Updated Successfully",success:true});
    } catch (err) {
        res.status(200).json({message: err.message,success:false});
    }
};

module.exports = updateController;