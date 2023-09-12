const delBtn = document.querySelector('.delete');

const storyId = sessionStorage.getItem('memoryId');

delBtn.addEventListener('click', (e) => {
    e.preventDefault();

    fetch(`/deleteStory?id=${savedValue}`)
    .then(res => res.json())
    .then(data => {
        if(data.success){
            alert(data.message);
            window.location.href = '/home';
        }else{
            alert(data.message);
            window.location.href = '/home';
        }
    })
    .catch(err => console.log(err));
});