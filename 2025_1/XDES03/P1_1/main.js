const productNameInputEl = document.querySelector("#input-product-name");
const productPriceInputEl = document.querySelector("#input-product-price");
const formEl = document.querySelector("form");
const productsListEl = document.querySelector("ul");
const calcPricesButtonEl = document.querySelector("#calculate-total");
const totalPricesTextEl = document.querySelector("#total-prices-amount");

const addProduct = (productName, productPrice) => {
  const newLiEl = document.createElement("li");

  const newPEl = document.createElement("p");
  newPEl.innerText = `${productName} — Preço: R$ `;
  newLiEl.append(newPEl);

  const newSpanEl = document.createElement("span");
  newSpanEl.innerText = Number(productPrice).toFixed(2);
  newPEl.append(newSpanEl);

  const newButtonEl = document.createElement("button");
  newButtonEl.innerText = "X";
  newButtonEl.setAttribute("type", "button");
  newButtonEl.addEventListener("click", removeProduct);
  newLiEl.append(newButtonEl);

  productsListEl.append(newLiEl);
};

const removeProduct = (event) => {
  const liEl = event.target.parentNode;

  liEl.remove();
};

const addProductSubmitHandler = (event) => {
  event.preventDefault();

  const productName = productNameInputEl.value;
  const productPrice = productPriceInputEl.value;

  if (productName === "" || productPrice === "") {
    alert("Preencha todos os campos.");

    return;
  }

  if (Number(productPrice) < 0) {
    alert("O preço não pode ser menor que zero.");

    return;
  }

  addProduct(productName, productPrice);

  productNameInputEl.value = "";
  productPriceInputEl.value = "";
};

const sumPricesClickHandler = () => {
  const total = [...productsListEl.childNodes].reduce(
    (acc, curr) =>
      (acc += Number(curr.childNodes[0].childNodes[1].textContent)),
    0
  );

  totalPricesTextEl.innerText = total.toFixed(2);
};

formEl.addEventListener("submit", addProductSubmitHandler);

calcPricesButtonEl.addEventListener("click", sumPricesClickHandler);
