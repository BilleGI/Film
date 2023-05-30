#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"
#include "film.h"

const std::string name("film.json") ;

void fillJson(nlohmann::json& jsonFilm, Film& film)
{
    jsonFilm["title"] = film.title;
    jsonFilm["country"] = film.country;
    jsonFilm["date"]["mon_day"] = film.date.tm_mday;
    jsonFilm["date"]["mon"] = film.date.tm_mon;
    jsonFilm["date"]["year"] = film.date.tm_year;
    jsonFilm["atelier"] = film.atelier;
    jsonFilm["auto script"] = film.autorScript;
    jsonFilm["director"] = film.director;
    jsonFilm["producer"] = film.producer;
    for(int i = 0; i < film.actors.size(); ++i)
    {
        jsonFilm["actors"][i]["actor name"] = film.actors[i].actorName;
        jsonFilm["actors"][i]["acting person"] = film.actors[i].actingPerson;
    }
}

int main()
{
    Film film;
    std::cout << "The program outputs information about the movie in JSON format." << std::endl;
    createFilm(film);
    nlohmann::json jsonFilm;
    fillJson(jsonFilm, film);
    std::ofstream file(name);
    file << jsonFilm;
    return 0;
}
