/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArticleItem.js                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:30:52 by amartino          #+#    #+#             */
/*   Updated: 2019/07/04 19:27:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { StyleSheet, View, Text, Image, TouchableOpacity, Dimensions, Shadow } from 'react-native'
import CardText from './CardText'
import { buttons, adders, images } from '../../styles/style.js'
import { colors, borderRadius, fonts, icon, image, padding, margin, dimensions, fontsSize, fontsWeight, fontsFamily } from '../../styles/base.js'
import { Mutation } from 'react-apollo';
import { graphql} from 'react-apollo';
import gql from 'graphql-tag';

class ArticleItem extends React.Component {

	render() {
		const { article, displayDetailForArticle, card_height, card_width, mutate } = this.props
		id = article.id
		if (article.isFavorite === true) {
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
			<TouchableOpacity
				style={[
					{
						width: card_width - (margin.lg * 2),
						height: card_height + padding.md,
					}, images.card_object, adders.shadow]}
				onPress={() => displayDetailForArticle(article)}
			>
				<View style={[styles.contain_images]}>
					<Image
					  style={[styles.image, images.card_image]}
					  source={{ uri: article.thumbnailUrl.replace(".webp", ".png") }}
					/>
					<TouchableOpacity
						onPress={() => mutate( { id } )}
						style={[styles.heart, images.card_icon]}
					>
						{img}
					</TouchableOpacity>
				</View>
			<CardText
				mainText={article.name}
				leftText={article.arrondissement}
				rightText={article.price}
			/>
	  	</TouchableOpacity>
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
	},
})

const MutationFavorite = gql`
  mutation ($id: ID!) {
    toggleFavorite(id: $id) @client
  }
`;

export default graphql(MutationFavorite, {
 options: (props) => ({ variables: { id: props.article.id} })
})(ArticleItem)
