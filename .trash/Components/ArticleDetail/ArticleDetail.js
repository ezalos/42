/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArticleDetail.js                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:26:02 by amartino          #+#    #+#             */
/*   Updated: 2019/07/03 12:08:52 by amartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { View, Text, StyleSheet, Image, Dimensions, ScrollView } from 'react-native';
import articles from '../../Helpers/db';
import MyImageCarousel from './MyImageCarousel'
import Slideshow from './SlideShow'
import AdditionalInfos from './AdditionalInfos'
import ArticleHeader from './ArticleHeader'
import ArticleImages from './ArticleImages'
import { Container, Spacer, Row, CategoryShortcuts, RowSA, AdditionalInfo, WrapRow, ArticleBox } from './../basic/view.js'
import { Title, Header, Description } from './../basic/text.js'
import {
	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
	fontsWeight, fontsFamily, image
} from '../../styles/base.js'

class ArticleDetail extends React.Component {


	_displayPrice(value) { 																												//underscore pour indiquer que la méthode est privée. this._displayLoading => OK | search._loadFilms => not OK even if it's working
		if (value == 2) {
			return (
				<Text selectable style={styles.price}>€€</Text>
			)
		}
		else if (value < 2)
			return (
				<Text selectable style={styles.price}>€</Text>
			)
		else
			return (
				<Text selectable style={styles.price}>€€€</Text>
			)
	}

	render() {
		const article = this.props.navigation.state.params.article
      return (

				<ScrollView style={styles.scrollview_container}>
					<ArticleImages article={article}/>
					<ArticleHeader article={article}/>
					<Text selectable style={styles.title}>{article.name}</Text>
					{this._displayPrice(article.price)}
					<ArticleBox>
						{article.text.split("  ").map((item, i) => (
							<Text key={item + i} selectable style={styles.description_text}>{item}</Text>
						))}
						<AdditionalInfos article={article}/>
					</ArticleBox>
				</ScrollView>
      )
    }
  }

const styles = StyleSheet.create({
  scrollview_container: {
    flex: 1,
		backgroundColor: colors.secondary_white,
  },
  description_text: {
    fontStyle: 'italic',
    color: '#666666',
		fontSize: 14,
		paddingHorizontal: 10,
    marginBottom: 15,
		paddingVertical: 10,
		lineHeight: 20,
		textAlign: 'justify',
  },
	title: {
		fontWeight: 'bold',
		fontSize: 32,
		paddingTop: 60,
		textAlign: 'center',
		textDecorationLine: 'underline',
		color: '#000000'
	},
	price: {
		fontWeight: 'bold',
		fontSize: 38,
		paddingHorizontal:30,
		marginVertical:15,
		marginBottom: 25,
		textAlign: 'center',
		color: '#DEDEDE'
	},
})

export default ArticleDetail
