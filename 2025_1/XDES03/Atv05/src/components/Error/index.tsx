import Image from "next/image";

import styles from "./styles.module.css";

export default function Error() {
  return (
    <div className={styles.container}>
      <p>Não conheço esse personagem :(</p>

      <Image alt="error image" src="/nooooooo.jpg" width={320} height={240} />
    </div>
  );
}
