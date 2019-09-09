/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapParis.js                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:00:21 by amartino          #+#    #+#             */
/*   Updated: 2019/07/01 19:46:09 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react';
import Svg,{
    Circle,
    Ellipse,
    G,
    TSpan,
    TextPath,
    Path,
    Polygon,
    Polyline,
    Line,
    Rect,
    Use,
    Symbol,
    Defs,
    LinearGradient,
    RadialGradient,
    Stop,
    ClipPath,
    Pattern,
    Mask,
} from 'react-native-svg';
import {
  Text, View, SafeAreaView, Button, StyleSheet, TouchableOpacity, Image
} from 'react-native'
import {
	Container, Spacer, Row, CategoryShortcuts, RowSA, AdditionalInfo,
	WrapRow, ArticleBox
} from './../basic/view.js'
import { Title, Header, Description } from './../basic/text.js'
import {
	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
	fontsWeight, fontsFamily, image
} from '../../styles/base.js'
import MapButtons from './MapButtons'



class MapParis extends React.Component {


  render() {
    return (
			<Container>
				<View style={styles.absolutVodka}>
					<MapButtons/>
					<Image
						style={styles.mapImage}
						source={require("../../assets/good/MapParis.png")}
					/>
				</View>
			</Container>
    )
  }
}

const styles = StyleSheet.create({
	searchModal: {
		flex: 1,
	},
	absolutVodka: {
	  	flex: 1,
		height: dimensions.width,
		width: dimensions.width,
		// backgroundColor: "blue",
	},
	mapImage: {
		flex: 1,
		height: undefined,
		width: undefined,
		resizeMode: 'contain',
	},
});

export default MapParis
