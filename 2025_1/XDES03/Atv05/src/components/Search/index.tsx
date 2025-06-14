import styles from "./styles.module.css";

interface SearchProps {
  formSubmitHandler: (event: React.FormEvent<HTMLFormElement>) => void;
  searchText: string;
  setSearchText: React.Dispatch<React.SetStateAction<string>>;
  status: string | undefined;
}

export default function Search({
  formSubmitHandler,
  searchText,
  setSearchText,
  status,
}: SearchProps) {
  return (
    <form className={styles.container} onSubmit={formSubmitHandler}>
      <input
        className={styles.input}
        id="input-name"
        name="input-name"
        onChange={(e) => setSearchText(e.currentTarget.value)}
        type="text"
        value={searchText}
      />
      <button
        className={styles.searchButton}
        disabled={searchText === "" || status === "loading"}
        type="submit"
      >
        Buscar
      </button>
    </form>
  );
}
