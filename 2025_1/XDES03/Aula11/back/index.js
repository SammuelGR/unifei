const express = require("express");
const fs = require("fs");
const path = require("path");

const app = express();

const dbPath = path.join("db", "disciplinas.json");

app.get("/disciplinas", (req, res) => {
  const { sigla } = req.query;

  const disciplinasStr = fs.readFileSync(dbPath, { encoding: "utf-8" });
  const disciplinas = JSON.parse(disciplinasStr);

  if (sigla) {
    const disciplina = disciplinas.find(
      (disc) => disc.sigla.toLowerCase() === sigla.toLowerCase()
    );

    if (disciplina) {
      res.status(200);
      res.send(disciplina);

      return;
    } else {
      res.status(404);
      res.send("Sigla não encontrada");

      return;
    }
  }

  res.status(200);
  return res.send(disciplinas);
});

app.listen(3000, () => {
  console.log("🚪 3000 ✅");
});
