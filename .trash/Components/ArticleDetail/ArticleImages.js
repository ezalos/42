/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArticleImages.js                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:26:02 by amartino          #+#    #+#             */
/*   Updated: 2019/07/02 21:10:44 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import {
	View, Text, StyleSheet, Image, Dimensions, ScrollView, TouchableOpacity
} from 'react-native';
import articles from '../../Helpers/db';
import Slideshow from './SlideShow'
import AdditionalInfos from './AdditionalInfos'
import ArticleHeader from './ArticleHeader'
import { Container, Spacer, Row, CategoryShortcuts, RowSA, AdditionalInfo, WrapRow, ArticleBox } from './../basic/view.js'
import { Title, Header, Description } from './../basic/text.js'
import {
	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
	fontsWeight, fontsFamily, image
} from '../../styles/base.js'
import { buttons, adders, images } from '../../styles/style.js'
import { Mutation } from 'react-apollo';
import { graphql} from 'react-apollo';
import gql from 'graphql-tag';


class ArticleImages extends React.Component {

	constructor(props) {
		super(props)
		this.state = {
			isFav: this.props.article.isFavorite
		}
	}

	_mutateFavorite = async (id) => {
		await this.props.mutate({ variables : { id } })
		this.setState({
			isFav : !this.state.isFav
		})
	}

	render() {
	const { article } = this.props
	if (this.state.isFav === false) {
		img = <Image
						style={[styles.heart]}
						source={require('../../assets/png/010-heart-off.png')}
					/>
	} else {
		img = <Image
						style={[styles.heart]}
						source={require('../../assets/png/011-heart-on.png')}
					/>
	}
    return (
			<Container>
		        <Slideshow article = {article}/>
				<View style={[styles.heart, images.card_icon]}>
					<TouchableOpacity
						onPress={() => this._mutateFavorite(article.id)}
						style={[styles.heart, images.card_icon]}
					>
						{img}
		      		</TouchableOpacity>
				</View>
			</Container>
    )
  }
}

const styles = StyleSheet.create({
	image: {
		width: Dimensions.get('window').width,
		height: Dimensions.get('window').height / 3,
		alignSelf: 'center',
		resizeMode: 'cover'
	},
	heart: {
		width: icon.md,
		height: icon.md,
	},
})

const MutationFavorite = gql`
  mutation toggleFavorite($id: ID!) {
    toggleFavorite(id: $id) @client
  }
`;

export default graphql(MutationFavorite, {
 options: (props) => ({ variables: { id: props.article.id} })
})(ArticleImages)
