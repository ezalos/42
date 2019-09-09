/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CardText.js                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 14:30:52 by amartino          #+#    #+#             */
/*   Updated: 2019/07/04 16:25:32 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { StyleSheet, View, Text, Image, TouchableOpacity, Dimensions, Shadow } from 'react-native'

class CardText extends React.Component {

	_displayPrice(value) { 																												//underscore pour indiquer que la méthode est privée. this._displayLoading => OK | search._loadFilms => not OK even if it's working
		if (value == 2) {
			return (
				<Text style={styles.date_text}>€€</Text>
			)
		}
		else if (value < 2)
			return (
				<Text style={styles.date_text}>€</Text>
			)
		else
			return (
				<Text style={styles.date_text}>€€€</Text>
			)
	}

	render() {
		const { mainText, leftText, rightText } = this.props

		return (
				<View style={styles.info}>
					<Text adjustsFontSizeToFit style={styles.title_text}>{mainText}</Text>
					<View style={styles.supplement}>
						<Text style={styles.vote_text}>{leftText}ᵉ</Text>
						{this._displayPrice(rightText)}
					</View>
				</View>
    )
  }
}

const styles = StyleSheet.create({
		info:{
			flex: 5,
			flexDirection: 'column',
			justifyContent: 'space-between',
			marginHorizontal: 5,
			marginTop: 10,
			marginVertical: 3
		},
			title_text: {
				flex: 2,
				flexWrap: 'wrap',
				fontWeight: 'bold',
				fontSize: 14,
				textAlign: 'center',
				textAlignVertical: 'top',
				color: '#000000'
			},
			supplement:{
				flex: 3,
				flexDirection: 'row',
				justifyContent: 'space-between',
				paddingHorizontal: 5,
				end: 0
			},
				vote_text: {
					flex: 1,
					fontSize: 20,
					textAlign: 'left',
					textAlignVertical: 'bottom',
					color: '#888888'
				},
				date_text: {
					flex: 1,
					fontSize: 18,
					textAlign: 'right',
					textAlignVertical: 'bottom',
					color: '#888888'
				}
})

export default CardText
