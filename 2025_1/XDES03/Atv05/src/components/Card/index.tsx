import Image from "next/image";

import { Character } from "@/models/Character";

import styles from "./styles.module.css";

interface CardProps {
  character: Character;
}

export default function Card({ character }: CardProps) {
  return (
    <div className={styles.container}>
      <p className={styles.name}>{character.name}</p>

      <div className={styles.imgContainer}>
        <Image
          alt={`character ${character.name}`}
          className={styles.img}
          fill
          src={character.image}
        />
      </div>

      <p className={styles.description}>{character.description}</p>
    </div>
  );
}
