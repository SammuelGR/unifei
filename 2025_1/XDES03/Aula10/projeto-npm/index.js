const axios = require("axios");

const url = "https://pokeapi.co/api/v2/pokemon/";

const getPokesAxios = async () => {
  const pokes = await axios.get(url);

  console.log(pokes.data.results);
};

getPokesAxios();

const getPokes = async () => {
  const response = await fetch(url, { method: "get" });

  const pokes = await response.json();

  console.log(pokes);
};

getPokes();
