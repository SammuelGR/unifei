const express = require("express");
const app = express();
const fs = require("fs");
const cors = require("cors");
const path = require("path");

app.use(express.json());
app.use(cors());

app.listen(3000, () => {
  console.log("Servidor na porta 3000");
});

const usersDbPath = path.join("db", "banco-dados-usuario.json");
const coursesDbPath = path.join("db", "cursos.json");

app.post("/login", (req, res) => {
  const { email, password } = req.body;

  const users = JSON.parse(fs.readFileSync(usersDbPath, { encoding: "utf-8" }));

  const emailExists = users.find((user) => user.email === email);

  if (!emailExists) {
    res
      .status(404)
      .send(
        `Usuario com email ${email} não existe. Considere criar uma conta!.`
      );

    return;
  }

  if (emailExists.password !== password) {
    res.status(400).send("Usuario ou senhas incorretas.");

    return;
  }

  res.status(200).send("Autenticado com Sucesso");
});

app.post("/create", (req, res) => {
  const { username, email, password } = req.body;

  const users = JSON.parse(fs.readFileSync(usersDbPath, { encoding: "utf-8" }));
  const emailExists = users.find((user) => user.email === email);

  if (emailExists) {
    res.status(400).send(`Usuario com email ${email} já existe.`);

    return;
  }

  const newUser = { id: users.length + 1, username, email, password };
  users.push(newUser);

  fs.writeFileSync(usersDbPath, JSON.stringify(users, null, 2), {
    encoding: "utf-8",
  });

  res.status(201).send("Tudo certo usuario criado com sucesso.");
});

app.get("/cursos", (_, res) => {
  const courses = JSON.parse(
    fs.readFileSync(coursesDbPath, { encoding: "utf-8" })
  );

  return res.json(courses);
});

app.get("/cursos/:nome", (req, res) => {
  const { nome } = req.params;

  const courses = JSON.parse(
    fs.readFileSync(coursesDbPath, { encoding: "utf-8" })
  );

  const filteredCourses = courses.filter((course) =>
    course.nome.toLocaleLowerCase().includes(nome.toLocaleLowerCase())
  );

  if (filteredCourses.length === 0) {
    res.status(404).send(`Curso ${nome} Não Encontrado!`);

    return;
  }

  res.json(filteredCourses);
});
