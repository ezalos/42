/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search.js                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:29:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/04/10 20:36:13 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Components/Search.js

import React from 'react'
import { StyleSheet, View, Text, TextInput, Button, FlatList } from 'react-native'
import films from '../Helpers/filmsData'
import FilmItem from './FilmItem'

class Search extends React.Component {
  render() {
    return (
// Ici on rend à l'écran les éléments graphiques de notre component custom Search
      <View style={styles.main_container}>
        <TextInput style={styles.textinput} placeholder='Titre du film'/>
        <Button title='Rechercher' onPress={() => {}}/>
		<FlatList
			data={films}
			keyExtractor={(item) => item.id.toString()}
			renderItem={({item}) => <FilmItem film={item}/>}
		/>
      </View>
    )
  }
}

const styles = StyleSheet.create({
	top_bar: {
		flex: 1,
		backgroundColor: 'black'
	},
	main_container: {
		flex: 1,
		marginTop: 24,
		backgroundColor: 'white'
	},
	textinput: {
		marginLeft: 5,
		marginRight: 5,
		height: 50,
		borderColor: '#000000',
		borderWidth: 1,
		paddingLeft: 5
	}
})

const stylesdb = StyleSheet.create({
	yellow: {
		flex: 1,
		backgroundColor: '#000000',
	},
	red: {
		flex: 1,
		backgroundColor: '#ffff00',
	},
	green: {
		flex: 2,
		backgroundColor: '#00ffff',
	},
	blue: {
		flex: 3,
		backgroundColor: '#ff00ff',
	}
})

export default Search
