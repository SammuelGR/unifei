const [player1ButtonEl, player2ButtonEl, resetScoreButtonEl] =
  document.querySelectorAll("button");
const [player1ScoreEl, player2ScoreEl] =
  document.querySelectorAll("#scoreboard span");
const selectScoresEl = document.querySelector("select");

const checkScore = () => {
  const scoreGoal = Number(selectScoresEl.value);

  if (Number(player1ScoreEl.textContent) === scoreGoal) {
    player1ButtonEl.classList.add("winner");
    player2ButtonEl.classList.add("looser");

    player1ButtonEl.setAttribute("disabled", "true");
    player2ButtonEl.setAttribute("disabled", "true");
  } else if (Number(player2ScoreEl.textContent) === scoreGoal) {
    player2ButtonEl.classList.add("winner");
    player1ButtonEl.classList.add("looser");

    player1ButtonEl.setAttribute("disabled", "true");
    player2ButtonEl.setAttribute("disabled", "true");
  }
};

const increaseScore = (playerId) => {
  const scoreEl = playerId === 1 ? player1ScoreEl : player2ScoreEl;

  scoreEl.textContent = Number(scoreEl.textContent) + 1;

  checkScore();
};

const resetScore = () => {
  player1ScoreEl.textContent = player2ScoreEl.textContent = 0;

  player1ButtonEl.classList.remove("winner", "looser");
  player1ButtonEl.removeAttribute("disabled");

  player2ButtonEl.classList.remove("winner", "looser");
  player2ButtonEl.removeAttribute("disabled");
};

player1ButtonEl.addEventListener("click", () => increaseScore(1));
player2ButtonEl.addEventListener("click", () => increaseScore(2));
resetScoreButtonEl.addEventListener("click", resetScore);
selectScoresEl.addEventListener("change", resetScore);
