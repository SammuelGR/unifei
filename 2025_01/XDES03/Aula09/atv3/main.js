const productNameInputEl = document.querySelector("#product-name");
const formEl = document.querySelector("form");
const productsListEl = document.querySelector("#products-list");

const inputSubmitHandler = (event) => {
  event.preventDefault();

  const nameValue = productNameInputEl.value;

  if (nameValue === "") {
    alert("Nome do produto não pode ser vazio");

    return;
  }

  addProduct(nameValue);
  productNameInputEl.value = "";
};

const addProduct = (productName) => {
  const newLiEl = document.createElement("li");

  const newPEl = document.createElement("p");
  const newSpanEl = document.createElement("span");
  const newBtnAddEl = document.createElement("button");
  const newBtnRemoveEl = document.createElement("button");

  newPEl.textContent = `${productName}. Quantidade: `;
  newSpanEl.textContent = "1";
  newPEl.append(newSpanEl);

  newBtnAddEl.textContent = "+";
  newBtnAddEl.style.backgroundColor = "green";
  newBtnAddEl.addEventListener("click", incrementProduct);

  newBtnRemoveEl.textContent = "-";
  newBtnRemoveEl.style.backgroundColor = "red";
  newBtnRemoveEl.addEventListener("click", decrementProduct);

  newLiEl.append(newPEl);
  newLiEl.append(newBtnAddEl);
  newLiEl.append(newBtnRemoveEl);

  productsListEl.append(newLiEl);
};

const incrementProduct = (event) => {
  const currentQuantity =
    Number(event.target.parentNode.childNodes[0].childNodes[1].innerText) + 1;

  event.target.parentNode.childNodes[0].childNodes[1].innerText =
    currentQuantity;
};

const decrementProduct = (event) => {
  const currentQuantity =
    Number(event.target.parentNode.childNodes[0].childNodes[1].innerText) - 1;

  if (currentQuantity <= 0) {
    event.target.parentNode.remove();
  } else {
    event.target.parentNode.childNodes[0].childNodes[1].innerText =
      currentQuantity;
  }
};

formEl.addEventListener("submit", inputSubmitHandler);
