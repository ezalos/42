/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Home.js                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:25:13 by amartino          #+#    #+#             */
/*   Updated: 2019/07/02 22:22:18 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import {
	StyleSheet, View, Text, Image, TouchableOpacity, Dimensions, ImageBackground,
	ListView, Animated, Shadow, Button, StatusBar, FlatList, Platform
} from 'react-native';
import articles from '../../Helpers/db'
import HomeIcon from './HomeIcon'
import ArticleItem from './../ArticleItem/ArticleItem'
import { Container, Spacer, Row, CategoryShortcuts } from './../basic/view.js'
import { Title, Header, Description } from './../basic/text.js'
import {
	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
	fontsWeight, fontsFamily, image
} from '../../styles/base.js'
import Articles from  './../../API/api'
import { graphql } from 'react-apollo';
import gql from 'graphql-tag';

const NAVBAR_HEIGHT = 65;

class Home extends React.Component {
	scroll = new Animated.Value(0);
	headerY;

	constructor(props) {
			super(props)
			this.headerY = Animated.multiply(Animated.diffClamp(this.scroll, 0, NAVBAR_HEIGHT), -1);
			this._category = this._category.bind(this)
	  }

	_category = (categoryTitle) => {
		this.props.navigation.navigate('Category', {categoryTitle: categoryTitle})
	}

	_displayDetailForArticle = (article) => {
		this.props.navigation.navigate("ArticleDetail", { article: article })
	}

	render() {
		const { getArticles, categories }  = this.props.data
		const tabY = Animated.add(this.scroll, this.headerY);
			return (
				<Container style={{backgroundColor: colors.secondary_white}}>
					<Animated.View
						style={{
							width: "100%",
							position: "absolute",
							transform: [{
								translateY: this.headerY
							}],
							elevation: 0,
							flex: 1,
							zIndex: 1,
							backgroundColor: colors.primary_white,
							borderBottomColor: '#dedede',
							borderBottomWidth: 1,
						}}
					>
						<Header> Par'idylle </Header>
						<CategoryShortcuts intermediateCategoryAccess={this._category}/>
					</Animated.View>
					<Animated.ScrollView
						scrollEventThrottle={1}
						bounces={false}
						showsVerticalScrollIndicator={false}
						style={{zIndex: 0, height: "100%", elevation: -1}}
						contentContainerStyle={{paddingTop: NAVBAR_HEIGHT}}
						onScroll={Animated.event(
							[{nativeEvent: {contentOffset: {y: this.scroll}}}],
							{useNativeDriver: true},
						)}
						overScrollMode="never">
						<FlatList
							data={getArticles}
							style={{paddingTop: NAVBAR_HEIGHT}}
							keyExtractor={(item) => item.id.toString()}
							renderItem={({item}) => (
								<ArticleItem
									article={item}
									displayDetailForArticle={this._displayDetailForArticle}
									card_height={image.lg_h}
									card_width={image.xl_w}
								/>
							)}
						/>
					</Animated.ScrollView>
				</Container>
	    )
	  }
	}

	const styles = StyleSheet.create({
		space:{
			flex: 1,
		},
	})


const QueryArticles = gql`
query {
	getArticles {
		id
		name
		adress
		arrondissement
		openings
		openingsSecondLine
		tel
		metro
		isFavorite
		metroImgUrls
		imgUrls
		thumbnailUrl
		latitude
		longitude
		coordinates {
			latitude
			longitude
		}
		subCategory {
			id
			name
			category {
				id
				name
			}
		}
		price
		weblink
		text
		updatedAt
		createdAt
	},
	categories {
		id
		name
		subCategories {
			id
			name
			category{
				id
				name
			}
			articles {
				id
				name
				adress
				arrondissement
				isFavorite
				openings
				openingsSecondLine
				tel
				metro
				metroImgUrls
				imgUrls
				thumbnailUrl
				latitude
				longitude
				price
				weblink
				text
				coordinates {
					latitude
					longitude
				}
				subCategory {
					id
					name
					category {
						id
						name
					}
				}
				updatedAt
				createdAt
			}
		}
	}
}
`;

export default graphql(QueryArticles)(Home);
