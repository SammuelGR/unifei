const express = require("express");
const fs = require("fs");
const path = require("path");

const app = express();
app.use(express.urlencoded({ extended: true }));

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
      res.status(200).send(disciplina);

      return;
    } else {
      res.status(404).send("Sigla não encontrada");

      return;
    }
  }

  return res.status(200).send(disciplinas);
});

app.post("/disciplinas", (req, res) => {
  const { sigla, ementa, equivalencia } = req.body;

  const disciplinasStr = fs.readFileSync(dbPath, { encoding: "utf-8" });
  const disciplinas = JSON.parse(disciplinasStr);

  const newDisc = {
    id: disciplinas.length + 1,
    sigla,
    ementa,
    equivalencia,
  };

  disciplinas.push(newDisc);

  fs.writeFileSync(dbPath, JSON.stringify(disciplinas, null, 2));

  return res.status(201).send("Disciplina criada com sucesso! 🏆");
});

app.listen(3000, () => {
  console.log("🚪 3000 ✅");
});
