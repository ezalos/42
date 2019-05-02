/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TMDBApi.js                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:48:13 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/24 11:19:36 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// API/TMDBApi.js

const API_TOKEN = "7f3aba5accb28475308643c198d94d1e";

export function getFilmsFromApiWithSearchedText (text, page) {
  const url = 'https://api.themoviedb.org/3/search/movie?api_key=' + API_TOKEN + '&language=fr&query=' + text + "&page=" + page
    return fetch(url)
    .then((response) => response.json())
    .catch((error) => console.error(error))
}
// Récupération du détail d'un film
export function getFilmDetailFromApi (id) {
  return fetch('https://api.themoviedb.org/3/movie/' + id + '?api_key=' + API_TOKEN + '&language=fr')
    .then((response) => response.json())
    .catch((error) => console.error(error));
}

export function getImageFromApi (name) {
  return 'https://image.tmdb.org/t/p/w300' + name
}
