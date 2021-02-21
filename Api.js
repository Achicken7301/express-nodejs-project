const API_KEY ='oA81cTs6tqbOVYHIaW1PuYxHlN79kSnn'
url = 'https://api.giphy.com/v1/gifs/random';
var test
const userInput = document.getElementById("test")
//getdata
async function getdata(){
  await userInput.addEventListener("input",function checkvalue(){
    test =document.getElementById("test").value
   return test
 })
  const FULL_url = url +'?api_key='+API_KEY+'&tag='+ test;
  const result=  await fetch(FULL_url) 
    .then(res => res.json())
    .catch(err => console.log(err))
  return result.data.image_url
}
//set data into .html
async function run(){
  const image =await getdata()
  const img =document.getElementById("image")
  img.src =image
}
run()