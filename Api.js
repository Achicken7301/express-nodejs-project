const API_KEY ='oA81cTs6tqbOVYHIaW1PuYxHlN79kSnn'
url = 'https://api.giphy.com/v1/gifs/random';
const userinput = document.getElementById('try')
var test
async function getImage(){
  const API_KEY ='oA81cTs6tqbOVYHIaW1PuYxHlN79kSnn'
  url = 'https://api.giphy.com/v1/gifs/random';
  const FULL_url = url +'?api_key='+API_KEY+'&tag='+ test;

const result=  await fetch(FULL_url) 
    .then(res => res.json())
    .catch(err => console.log(err))
return result.data.image_url
  }
  async function run(){
      const image =await getImage()
      const img =document.querySelector("#image")
      console.log(image)
      document.getElementById("image").src =image
    }
run()