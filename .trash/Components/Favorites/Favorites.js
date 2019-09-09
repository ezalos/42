/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Favorites.js                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:25:22 by amartino          #+#    #+#             */
/*   Updated: 2019/07/04 17:29:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { View, StyleSheet, FlatList, Text, Image, TouchableOpacity, Dimensions, Shadow } from 'react-native';
import {
	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
	fontsWeight, fontsFamily, image
} from '../../styles/base.js'
import { buttons, adders, images } from '../../styles/style.js'
import { Container, Spacer, Row, CategoryShortcuts } from './../basic/view.js'
import { Title, Header, Description, MainHeader } from './../basic/text.js'
import CardText from '../ArticleItem/CardText'
import ArticleItem from './../ArticleItem/ArticleItem'
import { graphql } from 'react-apollo';
import gql from 'graphql-tag';


let example = {
	  "arrondissement": 12,
	  "name": "Un excellent article",
	  "price": 3,
  	  "isFavorite": false,
	  "thumbnailUrl": "http://hiladt.com/wordpress/wp-content/uploads/Light-Gray-Background-Png-light-grey-background-pattern-i31-114065.jpg",
  }

class Favorites extends React.Component {

	constructor(props) {
		super(props)
		this.state = {
			isFav: example.isFavorite
		}
	}

	_changeExample = async () => {
		this.setState(state => ({
			isFav : !state.isFav
		}))
	}

	_displayDetailForArticle = (article) => {
		this.props.navigation.navigate("ArticleDetail", { article: article })
	}


	render() {
		const { getArticles }  = this.props.data
		let favoriteArticle;

		favoriteArticle = getArticles.filter(
			(item) => {
				return item.isFavorite === true
			}
		)

		if (this.state.isFav) {
			img = <Image
					style={[styles.heart]}
					source={require('../../assets/png/011-heart-on.png')}
				/>
		} else {
			img = <Image
					style={[styles.heart]}
					source={require('../../assets/png/010-heart-off.png')}
				/>
		}

		return (
			<View>
				<MainHeader>Favoris</MainHeader>
				<Container style={{borderTopWidth: 1, borderTopColor: colors.tertiary_white,}}/>
			  {
			    favoriteArticle.length > 0 ? (
	  				<FlatList
	  					data={favoriteArticle}
	  					style={{paddingTop: 0}}
	    				numColumns={2}
	  					keyExtractor={(item) => item.id.toString()}
	  					renderItem={({item}) => (
	  						<ArticleItem
	  							article={item}
	  							displayDetailForArticle={this._displayDetailForArticle}
	  							card_height={image.md_h}
	  							card_width={image.lg_w}
	  						/>
	  					)}
	  				/>
				) :
				<View style={{height: image.xl_h, backgroundColor: colors.one_and_an_half_white}}>
					<Text style={styles.infos}>Pour ajouter un article a tes favoris, clique sur le coeur.</Text>
					<TouchableOpacity
						style={[
							{
								width: image.xl_w - (margin.md * 2),
								height: image.lg_h + padding.md,
							}, images.card_object, adders.shadow]}
					>
						<View style={[styles.contain_images]}>
							<Image
							  style={[images.card_image, styles.image, {resizeMode: 'contain'}]}
							  source={require('../../assets/good/arrow.png')}
							/>
							<TouchableOpacity
								onPress={() => this._changeExample()}
								style={[styles.heart, images.card_icon]}
							>
								{img}
							</TouchableOpacity>
						</View>
					<CardText
						mainText={example.name}
						leftText={example.arrondissement}
						rightText={example.price}
					/>
				  	</TouchableOpacity>
				</View>
			}
		  </View>
		)
	}
}

const styles = StyleSheet.create({
	image: {
		flex: 1,
		width: undefined,
		height: undefined
	},
	heart: {
		width: icon.md,
		height: icon.md,
	},
	contain_images: {
		flex: 20,
		backgroundColor: colors.primary_white,
	},
	bandeau_title: {
		fontSize: 45,
		color: colors.primary_black,
		fontWeight: 'bold',
		textAlign: 'center',
		padding: 5,
		backgroundColor: colors.primary_white,
		// borderBottomWidth: 10,
		// borderBottomColor: colors.primary_black,
	},
	infos: {
		flex: 1,
		flexWrap: 'wrap',
		fontSize: 14,
		color: colors.secondary_black,
		textAlign: 'left',
		paddingBottom: 15,
		paddingTop: 30,
		margin: 10,
		backgroundColor: colors.transparent,
	},
	titleInfos: {
		flex: 1,
		flexWrap: 'wrap',
		fontSize: 18,
		color: colors.primary_black,
		textAlign: 'left',
		paddingBottom: 15,
		paddingTop: 30,
		margin: 5,
		backgroundColor: colors.primary_white,
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
		}
	}
`;

export default graphql(QueryArticles)(Favorites);
