const express = require("express");
const fs = require("fs");
const path = require("path");

const dbPath = path.join("db", "disciplinas.json");

const app = express();

app.get("/login", (req, res) => {
  const { name, password } = req.query;

  const msg = `hola ${name}, your senha es ${password}`;

  res.send(msg);
});

app.get("/disciplinas", (req, res) => {
  const disciplinasString = fs.readFileSync(dbPath, { encoding: "utf-8" });
  const disciplinas = JSON.parse(disciplinasString);

  res.send(disciplinas);
});

app.listen(3000, () => {
  console.log("listening port 3000");
});
