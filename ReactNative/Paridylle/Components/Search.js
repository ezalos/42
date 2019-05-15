/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Search.js                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:29:20 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/11 14:23:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Components/Search.js

import React from 'react'
import FilmItem from './FilmItem'
import { getFilmsFromApiWithSearchedText } from '../API/TMDBApi'
import { StyleSheet, View, TextInput, Button, Text, FlatList, ActivityIndicator, ScrollView } from 'react-native'

class Search extends React.Component {

	constructor(props) {														//constructors are for: Initializing local state by assigning an object to this.state / Binding event handler methods to an instance.
		super(props)															//super refers to the parent class constructor. Here : React.Component
		this.searchedText = "Star"													//		We need to call super in order to access to this.props. Otherwise, this.props will be undefined
		this.page = 0
		this.totalPages = 0
		this.state = {															//Constructor is the only place where you should assign this.state directly. You should not call setState() in the constructor().
			films: [],															//		Avoid copying props into state!
			isLoading: false
		};
	}

	_displayDetailForFilm = (idFilm) => {
		console.log("Display film with id " + idFilm)
		this.props.navigation.navigate("FilmDetail", { idFilm: idFilm })		// seulement idFilm
	}

	_displayLoading() { 														//underscore pour indiquer que la méthode est privée. this._displayLoading => OK | search._loadFilms => not OK even if it's working
		if (this.state.isLoading) {
			return (
				<View style={styles.loading_container}>
					<ActivityIndicator size='large' />
				</View>
			)
		}
	}

	_searchTextInputChanged(text) {
		this.searchedText = text
	}

	_searchFilms() {
		this.page = 0
		this.totalPages = 0
		this.setState({															//setState is an asynchrome function. It enqueues changes to the component state and tells React
			films: []															//		that this component and its children need to be re-rendered with the updated state.
		}, () => {																//		React does not guarantee that the state changes are applied immediately. (printf like)
			this._loadFilms()													//		This makes reading this.state right after calling setState() a potential pitfall.
		})																		//		Instead, use componentDidUpdate or a setState callback (setState(updater, callback)) like here.
	}

	_loadFilms() {
		if (this.searchedText.length > 0) {
			this.setState({ isLoading: true })
			getFilmsFromApiWithSearchedText(this.searchedText,
			this.page + 1).then(data => { 										//Can we put 2 .then ?
				this.page = data.page
				this.totalPages = data.total_pages
				this.setState({
					films: [ ...this.state.films, ...data.results ],			//equal -> films: this.state.films.concat(data.results)
					isLoading: false
				})
			})
		}
	}

 	render() {																	//Render is the only method you must define in a React.Component subclass. When called,
		return (																//		it should examine this.props and this.state and return one of the following types: React element / Arrays and fragments / Portal / String and Numbers / Booleans or null
																				//		It should be pure, meaning that it does not modify component state
		<View style={styles.main_container}>
	    	<TextInput
				style={styles.textinput}
				placeholder='Titre du film'										//The string that will be rendered before text input has been entered.
				onChangeText={(text) => this._searchTextInputChanged(text)}		//Callback that is called when the text input's text changes. Changed text is passed as a single string argument to the callback handler.
				onSubmitEditing={() => this._searchFilms()}						//Callback that is called when the text input's submit button is pressed
			/>
	    	<Button title='Rechercher' onPress={() => this._searchFilms()}/>
																				{/*Same as onSubmitEditing*/}

<ScrollView style={styles.scrollview_container}>
			<View style={styles.sideList}>
				<Text style={styles.bandeau_title}>Ta mere</Text>
	    	<FlatList
				horizontal
	         	data={this.state.films}
	         	keyExtractor={(item) => item.id.toString()}
	         	renderItem={({item}) => <FilmItem film={item} displayDetailForFilm=
				{this._displayDetailForFilm} />}
				onEndReachedThreshold={0.5}
			    onEndReached={() => {
			      if (this.page < this.totalPages) {
					  this._loadFilms()
				  }
			    }}
			/>
			{this._displayLoading()}
																				{/*Cette fonction peut être mise n'importe ou ds le render. Les fonctions appelées dans le render doivent
																						 obligatoirement retourner des éléments graphiques, c-a-d des components. return "coucou" ne fonctionnera pas*/}
																						 <View style={styles.spacing}/>
			</View>


			<View style={styles.sideList}>
				<Text style={styles.bandeau_title}>Ton pere</Text>
				<FlatList
				horizontal
						data={this.state.films}
						keyExtractor={(item) => item.id.toString()}
						renderItem={({item}) => <FilmItem film={item} displayDetailForFilm=
				{this._displayDetailForFilm} />}
				onEndReachedThreshold={0.5}
					onEndReached={() => {
						if (this.page < this.totalPages) {
						this._loadFilms()
					}
					}}
			/>
			<View style={styles.spacing}/>
			</View>

			<View style={styles.sideList}>
				<Text style={styles.bandeau_title}>Ton frere</Text>
				<FlatList
				horizontal
						data={this.state.films}
						keyExtractor={(item) => item.id.toString()}
						renderItem={({item}) => <FilmItem film={item} displayDetailForFilm=
				{this._displayDetailForFilm} />}
				onEndReachedThreshold={0.5}
					onEndReached={() => {
						if (this.page < this.totalPages) {
						this._loadFilms()
					}
					}}
			/>
			<View style={styles.spacing}/>
			</View>

			<View style={styles.sideList}>
				<Text style={styles.bandeau_title}>Ta soeur</Text>
				<FlatList
				horizontal
						data={this.state.films}
						keyExtractor={(item) => item.id.toString()}
						renderItem={({item}) => <FilmItem film={item} displayDetailForFilm=
				{this._displayDetailForFilm} />}
				onEndReachedThreshold={0.5}
					onEndReached={() => {
						if (this.page < this.totalPages) {
						this._loadFilms()
					}
					}}
			/>
			<View style={styles.spacing}/>
			</View>

			</ScrollView>
     	</View>
	)
 	}
}

const styles = StyleSheet.create({
	main_container: {															//By default flexDirection is column
		flex: 1
	},
	scrollview_container: {
	flex: 1
	},
	bandeau_title: {
      	fontSize: 45,
		color: '#606090',
    fontWeight: 'bold',
		padding: 5,
		paddingLeft: 10,
		backgroundColor: '#fdfdfd'
	},
  linearGradient: {
    flex: 1,
    paddingLeft: 15,
    paddingRight: 15,
    borderRadius: 5
  },
	spacing: {
		height: 1
	},
	sideList: {
		flexDirection: 'column',
		backgroundColor: '#fafafa'
	},
	textinput: {
		marginLeft: 5,
		marginRight: 5,
		height: 50,
		borderColor: '#000000',
		borderWidth: 1,
		paddingLeft: 5
	},
	loading_container: {
		position: 'absolute',
		left: 0,
		right: 0,
		top: 90,
		bottom: 0,
		alignItems: 'center',													//alignItem is on the horizontal axis X (when flexDirection=Column)
		justifyContent: 'center'												//justifyContent is on the vertical axis Y
	}
})

export default Search
