import axios from "axios";

export const starWarsDatabankApi = axios.create({
  baseURL: "https://starwars-databank-server.vercel.app/api/v1/",
});
