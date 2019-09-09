/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Category.js                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:24:25 by amartino          #+#    #+#             */
/*   Updated: 2019/07/04 21:32:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import ArticleItem from './../ArticleItem/ArticleItem'
import CategoryCarousel from './CategoryCarousel'
import { StyleSheet, View, TextInput, Button, Text, FlatList, ActivityIndicator,
	 ScrollView
 } from 'react-native'
 import {
 	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
 	fontsWeight, fontsFamily, image
 } from '../../styles/base.js'
 import { Container, Spacer, Row, CategoryShortcuts } from './../basic/view.js'
 import { Title, Header, Description, MainHeader, ParHeader } from './../basic/text.js'
import articles from '../../Helpers/db';
import { ApolloProvider, graphql, Query } from 'react-apollo';
import { ApolloClient } from 'apollo-client';
import { HttpLink } from 'apollo-link-http';
import { InMemoryCache } from 'apollo-cache-inmemory';
import gql from 'graphql-tag';
import { buttons, adders } from '../../styles/style.js'

class Category extends React.Component {

		constructor(props) {																												//constructors are for: Initializing local state by assigning an object to this.state / Binding event handler methods to an instance.
			super(props)																															//super refers to the parent class constructor. Here : React.Component //		We need to call super in order to access to this.props. Otherwise, this.props will be undefined
			this.state = {																														//Constructor is the only place where you should assign this.state directly. You should not call setState() in the constructor().
				films: [],																															//		Avoid copying props into state!
				isLoading: false
			};
		}

		_displayLoading() { 																												//underscore pour indiquer que la méthode est privée. this._displayLoading => OK | search._loadFilms => not OK even if it's working
			if (this.state.isLoading) {
				return (
					<View style={styles.loading_container}>
						<ActivityIndicator size='large' />
					</View>
				)
			}
		}

	render() {
		const { categories } = this.props.data
		const  { categoryTitle } = this.props.navigation.state.params
		if (categoryTitle == "Par'Appetit") {
			categoryValue = 0
		}
		if (categoryTitle == "Par'Ivresse") {
			categoryValue = 1
		}
		if (categoryTitle == "Par'Gourmandise") {
			categoryValue = 2
		}
		if (categoryTitle == "Par'Passion") {
			categoryValue = 3
		}
		if (categoryTitle == "Par'Ailleurs") {
			categoryValue = 4
		}
		return (
			<Container>
				<ParHeader> {categories[categoryValue].name.toLowerCase().charAt(0).toUpperCase() + categories[categoryValue].name.toLowerCase().slice(1)} </ParHeader>
				<ScrollView style={[styles.scrollview_container, {backgroundColor: colors.secondary_white}]}>
			    	<FlatList
				       	data={categories[categoryValue].subCategories}
				       	keyExtractor={(item) => item.id.toString()}
						renderItem={({item}) => (
							<CategoryCarousel
								style={adders.shadow}
								categoryValue={categoryValue}
								subCategoryTitle={item.name}
								subCategoryId={item.id}
								navigation={this.props.navigation}
							/>
						)}
					/>
				</ScrollView>
			</Container>
	)
 	}
}

const styles = StyleSheet.create({
	scrollview_container: {
		flex: 1,
	},
	loading_container: {
		position: 'absolute',
		left: 0,
		right: 0,
		top: 90,
		bottom: 0,
		alignItems: 'center',																												//alignItem is on the horizontal axis X (when flexDirection=Column)
		justifyContent: 'center'																										//justifyContent is on the vertical axis Y
	}
})

const QueryCategories = gql`
query {
	categories {
		id
		name
		subCategories {
			id
			name
		}
	}
}
`;

export default graphql(QueryCategories)(Category);
