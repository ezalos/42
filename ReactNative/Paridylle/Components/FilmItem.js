/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FilmItem.js                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:57:37 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/01 18:07:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Components/FilmItem.js
import React from 'react'
import { StyleSheet, View, Text, Image, TouchableOpacity } from 'react-native'
import { getImageFromApi } from '../API/TMDBApi' // import { } from ... car c'est un export nommé dans TMDBApi.js

class FilmItem extends React.Component {
  render() {
    // console.log(this.props)
	const { film, displayDetailForFilm } = this.props
	//ligne du dessus similaire a ces deux lignes :
	//	const film = this.props.film
	//	const displayDetailForFilm = this.props.displayDetailForFilm
    return (
		<TouchableOpacity
			style={styles.card}
			onPress={() => displayDetailForFilm(film.id)}>

			<View style={styles.pic_content}>
		        <Image
		          style={styles.image}
		          source={{uri: getImageFromApi(film.poster_path)}}
		        />
				<Image
				  style={styles.heart}
		          source={require('/Users/ldevelle/42/ReactNative/Paridylle/assets/heart.png')}
		        />
			</View>
			<View style={styles.info}>
				<Text style={styles.title_text}>{film.title}</Text>
				<View style={styles.supplement}>
					<Text style={styles.vote_text}>{film.vote_average}ᵉ</Text>
					<Text style={styles.date_text}>€€€</Text>
				</View>
			</View>
	  </TouchableOpacity>
    )
  }
}

const styles = StyleSheet.create({
	card: {
		width: 150,
		height: 250,
		flexDirection: 'column',
		marginVertical: 5,
		marginHorizontal: 7,
		borderRadius:10,
		borderWidth: 1,
		borderColor: '#fff'
	},
		pic_content: {
			width: 150,
			height: 150,
			borderRadius:10,
			borderWidth: 1,
			borderColor: '#fff'
		},
			image: {
				width: 150,
				height: 150,
				borderRadius:10,
				borderWidth: 1,
				borderColor: '#fff',
				resizeMode: 'cover'
			},
			heart: {
				position: 'absolute',
				top: 5,
				right: 5,
				width: 30,
				height: 30,
				resizeMode: 'center'
			},
		info:{
			flex: 5,
			flexDirection: 'column',
			justifyContent: 'space-between',
			marginHorizontal: 5,
			marginVertical: 3
		},
			title_text: {
				flex: 2,
				flexWrap: 'wrap',
				fontWeight: 'bold',
				fontSize: 14,
				textAlign: 'center',
				textAlignVertical: 'top',
				color: '#000000'
			},
			supplement:{
				flex: 3,
				flexDirection: 'row',
				justifyContent: 'space-between',
				paddingHorizontal: 5,
				end: 0
			},
				vote_text: {
					flex: 1,
					fontSize: 20,
					textAlign: 'left',
					textAlignVertical: 'bottom',
					color: '#888888'
				},
				space: {
					flex: 1,
				},
				date_text: {
					flex: 1,
					fontSize: 18,
					textAlign: 'right',
					textAlignVertical: 'bottom',
					color: '#888888'
				}
})

export default FilmItem