import { starWarsDatabankApi } from "@/services/starWars";

export const getCharacter = (name: string) => {
  return starWarsDatabankApi.get(`characters/name/${name}`);
};
