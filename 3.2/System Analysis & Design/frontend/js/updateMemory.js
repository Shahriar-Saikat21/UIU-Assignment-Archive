const memId = sessionStorage.getItem('memoryId');

function dataForUpdate(){
    fetch(`/updateMemoryData?id=${memId}`)
    .then(res=>res.json())
    .then(data=>{
        if(data.success){
            document.querySelector('.title').value = data.memory.title;
            document.querySelector('.memory').value = data.memory.story;
        }else{
            alert(data.message);
            window.location.href = '/home';
        }
    })
    .catch(err=>{console.log(err)});
}

dataForUpdate();

const updateBtn = document.querySelector('.updateBtn');

updateBtn.addEventListener('click',(e)=>{
    e.preventDefault();

    const title = document.querySelector('.title').value;
    const story = document.querySelector('.memory').value;

    fetch(`/updateMemory?id=${memId}`,{
        method: "PUT",
        headers: {
            "Content-Type" : "application/json"
        },
        body: JSON.stringify({title,story})
    })
    .then(res=>res.json())
    .then(data=>{
        if(data.success){
            alert(data.message);
            window.location.href = '/home';
        }else{
            alert(data.message);
            window.location.href = '/home';
        }
    }).catch(err=>{console.log(err)});
});