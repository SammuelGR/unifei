import styles from "./styles.module.css";

export default function Footer() {
  return (
    <footer className={styles.footer}>
      <small>
        © Alguns direitos reservados. Feito com 🥶 por{" "}
        <a
          href="http://github.com/sammuelgr"
          target="_blank"
          rel="noopener noreferrer"
        >
          Sammuel
        </a>
      </small>
    </footer>
  );
}
