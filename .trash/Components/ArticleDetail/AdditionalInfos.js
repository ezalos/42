/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AdditionalInfos.js                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:26:02 by amartino          #+#    #+#             */
/*   Updated: 2019/07/02 22:06:35 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { View, Text, StyleSheet, Image, Dimensions, ScrollView } from 'react-native';
import articles from '../../Helpers/db';
import MyImageCarousel from './MyImageCarousel'
import Slideshow from './SlideShow'
import { Container, Spacer, Row, CategoryShortcuts, RowSA, AdditionalInfo, WrapRow } from './../basic/view.js'
import { Title, Header, Description } from './../basic/text.js'
import {
	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
	fontsWeight, fontsFamily, image
} from '../../styles/base.js'

class AdditionalInfos extends React.Component {

		constructor(props) {														//constructors are for: Initializing local state by assigning an object to this.state / Binding event handler methods to an instance.
			super(props)
		}

	_displayOpening() {
		if (this.props.article.openingsSecondLine){
			return (
				<Text selectable style={styles.top_info}>
					{this.props.article.openingsSecondLine}
				</Text>
			)
		}
	}
	render() {

		const {article} = this.props

      return (
		<WrapRow>
			{ article.openings ? (
				<AdditionalInfo>
				    <Image
				      style={styles.heart}
				      source={require("../../assets/good/Openings.png")}
				    />
					<View style={{ flexDirection: 'column', }}>
						<Text selectable style={styles.top_info}>{article.openings}</Text>
						{this._displayOpening()}
					</View>
				</AdditionalInfo>
			) : null }
			{ article.tel ? (
				<AdditionalInfo>
					<Image
						style={styles.heart}
						source={require("../../assets/good/Phone.png")}
					/>
					<Text selectable style={styles.top_info}>{article.tel}</Text>
				</AdditionalInfo>
			) : null }
			{ article.metro ? (
				<AdditionalInfo>
			        <Image
			          style={styles.heart}
			          source={require("../../assets/good/Metro.png")}
			        />
					<Text selectable style={styles.top_info}>{article.metro}</Text>
					{article.metroImgUrls.map((item) => (
			        <Image
			        	style={styles.heart}
						key={item}
			        	source={{uri: item.replace(".webp", ".png")}}
			        />
					))}
				</AdditionalInfo>
			) : null }
			{ article.adress ? (
				<AdditionalInfo>
					<Image
					  style={styles.heart}
					  source={require("../../assets/good/Adress.png")}
					/>
					<Text selectable style={styles.top_info}>{article.adress}</Text>
				</AdditionalInfo>
			) : null }
		</WrapRow>
      )
    }
  }

const styles = StyleSheet.create({
	top_info: {
	  color: '#666666',
	  margin: 5,
	  fontSize: 12,
	  textAlign: 'center',
		flexWrap: 'wrap',
	},
	heart: {
		width: 20,
		height: 20,
		resizeMode: 'contain',
	},
})

export default AdditionalInfos
