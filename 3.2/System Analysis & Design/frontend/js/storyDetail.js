const image = document.querySelector('.image');
const title = document.querySelector('.hTag');
const date = document.querySelector('.dTag');
const detail = document.querySelector('.pTag');

const savedValue = sessionStorage.getItem('memoryId');
//sessionStorage.clear();

function storyDisplay(){
    fetch(`/storyDetail?id=${savedValue}`)
    .then(res => res.json())
    .then(data => {
        if(data.success){
            image.src = `data:${data.memory.image.contentType};base64,${arrayBufferToBase64(data.memory.image.data.data)}`;
            title.innerHTML = data.memory.title;
            date.innerHTML = data.memory.date;
            detail.innerHTML = data.memory.story;
        }else{
            window.location.href = "/home";
        }
    })
    .catch(err => console.log(err.message));
}

function arrayBufferToBase64(buffer) {
    let binary = '';
    const bytes = new Uint8Array(buffer);
    const len = bytes.byteLength;
    for (let i = 0; i < len; i++) {
      binary += String.fromCharCode(bytes[i]);
    }
    return window.btoa(binary);
}

storyDisplay();