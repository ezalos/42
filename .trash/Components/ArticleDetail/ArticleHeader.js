/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArticleHeader.js                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:26:02 by amartino          #+#    #+#             */
/*   Updated: 2019/07/04 15:43:48 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import {
	View, Text, StyleSheet, Image, Dimensions, ScrollView, TouchableOpacity
} from 'react-native';
import articles from '../../Helpers/db';
import MyImageCarousel from './MyImageCarousel'
import Slideshow from './SlideShow'
import AdditionalInfos from './AdditionalInfos'
import { Container, Spacer, Row, CategoryShortcuts, RowSA, AdditionalInfo, WrapRow } from './../basic/view.js'
import { Title, Header, Description } from './../basic/text.js'
import {
	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
	fontsWeight, fontsFamily, image
} from '../../styles/base.js'

class ArticleHeader extends React.Component {
	render() {
		const {article} = this.props
      return (
				<RowSA>
					<Image
						source={require("../../assets/good/Share.png")}
						style={styles.icon}
					/>
					<Spacer/>
					<Text style={styles.subCat}>{article.subCategory.name}</Text>
					<Spacer/>
					<Image
						source={require('../../assets/good/Map.png')}
						style={styles.icon}
					/>
				</RowSA>
      )
    }
  }

const styles = StyleSheet.create({
	icon: {
		height: icon.md,
		width: icon.md,
		flex: 1,
		resizeMode: 'contain',
	},
	subCat: {
		fontSize: 24,
		color: '#DEDEDE'
	},
})

export default ArticleHeader
