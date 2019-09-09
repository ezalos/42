/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubCategory.js                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:24:55 by amartino          #+#    #+#             */
/*   Updated: 2019/07/04 19:31:40 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { StyleSheet, View, TextInput, Button, Text, FlatList, ActivityIndicator,
	 ScrollView
 } from 'react-native'
import {
 	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
 	fontsWeight, fontsFamily, image
 } from '../../styles/base.js'
 import { Container, Spacer, Row, CategoryShortcuts } from './../basic/view.js'
 import { Title, Header, Description, MainHeader } from './../basic/text.js'
import ArticleItem from './../ArticleItem/ArticleItem'
import { buttons, adders, images } from '../../styles/style.js'

class SubCategory extends React.Component {

	_displayDetailForArticle = (article) => {
		this.props.navigation.navigate("ArticleDetail", { article: article })
	}

	render() {
		const articles = this.props.navigation.state.params.articles
		const subCategoryTitle = this.props.navigation.state.params.subCategoryTitle

		return (
			<View style={styles.wesh} >
				<MainHeader>{subCategoryTitle}</MainHeader>
				<FlatList
					data={articles}
					style={{paddingTop: 0}}
					keyExtractor={(item) => item.id.toString()}
					renderItem={({item}) => (
						<ArticleItem
							article={item}
							displayDetailForArticle={this._displayDetailForArticle}
							card_height={image.lg_h - (image.lg_h / 4)}
							card_width={image.xl_w}
						/>
					)}
				/>
			</View>
		)
	}
}

const styles = StyleSheet.create({
	wesh:{
		flex: 1,
	},
	bandeau_title: {
		fontSize: 45,
		color: colors.primary_black,
		fontWeight: 'bold',
		textAlign: 'center',
		padding: 5,
		backgroundColor: colors.primary_white,
	},
})

export default SubCategory
