export default function Pokemon({ name, imgUrl }) {
  return (
    <div>
      <p>{name}</p>

      <img src={imgUrl} alt="um pokemon" />
    </div>
  );
}
