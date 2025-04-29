const formEl = document.querySelector("form");
const inputNameEl = document.querySelector("#product-name");
const inputQuantityEl = document.querySelector("#quantity");
const placeholderEl = document.querySelector("#empty-placeholder");
const productsListEl = document.querySelector("ul");

const removeProduct = (event) => {
  const removeButtonEl = event.target;

  removeButtonEl.parentElement.remove();

  const itemsLength = productsListEl.childNodes.length;

  if (itemsLength === 0) {
    placeholderEl.style.display = "unset";
  }
};

const onFormSubmit = (event) => {
  event.preventDefault();

  if (inputNameEl.value === "" || inputQuantityEl.value === "") {
    alert("Preencha todos os campos.");

    return;
  }

  const nameValue = inputNameEl.value;
  const quantityValue = Number.parseInt(inputQuantityEl.value, 10);

  const newLiEl = document.createElement("li");
  newLiEl.innerText = `${quantityValue}: ${nameValue} `;

  const newRemoveButtonEl = document.createElement("button");
  newRemoveButtonEl.innerText = "X";
  newRemoveButtonEl.addEventListener("click", removeProduct);

  newLiEl.append(newRemoveButtonEl);
  productsListEl.append(newLiEl);

  inputNameEl.value = "";
  inputQuantityEl.value = "";

  placeholderEl.style.display = "none";
};

formEl.addEventListener("submit", onFormSubmit);
