const mainEl = document.querySelector("main");
const spanEl = document.querySelector("span");
const buttonEl = document.querySelector("button");

const getRandomColors = () => {
  const colors = {
    r: Math.trunc(Math.random() * 256),
    g: Math.trunc(Math.random() * 256),
    b: Math.trunc(Math.random() * 256),
  };

  return colors;
};

const changeColor = () => {
  const newColor = getRandomColors();
  const colorText = `rgb(${newColor.r}, ${newColor.g}, ${newColor.b})`;

  mainEl.style.backgroundColor = colorText;
  spanEl.innerText = colorText;
};

buttonEl.addEventListener("click", changeColor);
