"use client";

import Image from "next/image";
import { useState } from "react";

import Footer from "@/components/Footer";
import { getCharacter } from "@/fetchers/characters";
import { Character } from "@/models/Character";
import { capitalizeWords } from "@/utils/string";

import StarWarsLogo from "../../public/Star_Wars_Logo.svg";
import styles from "./page.module.css";
import Error from "@/components/Error";
import Card from "@/components/Card";
import Search from "@/components/Search";

export default function Home() {
  const [searchText, setSearchText] = useState("");
  const [character, setCharacter] = useState<Character | undefined>(undefined);
  const [status, setStatus] = useState<string | undefined>(undefined);

  const formSubmitHandler = async (event: React.FormEvent<HTMLFormElement>) => {
    event.preventDefault();
    setStatus("loading");
    setCharacter(undefined);

    const response = (await getCharacter(capitalizeWords(searchText))).data[0];

    if (!response) {
      setStatus("error");
      return;
    }

    setSearchText("");
    setCharacter({ ...response, id: response._id });
    setStatus("loaded");
  };

  return (
    <>
      <main className={styles.main}>
        <Image alt="Star Wars Logo" src={StarWarsLogo} width={240} />

        <h1 className={styles.pageTitle}>
          A long time ago in a galaxy far far away...
        </h1>

        <section>
          <Search
            formSubmitHandler={formSubmitHandler}
            searchText={searchText}
            setSearchText={setSearchText}
            status={status}
          />
        </section>

        <section>
          {status !== "error" && character && <Card character={character} />}
          {status === "error" && <Error />}
        </section>
      </main>

      <Footer />
    </>
  );
}
