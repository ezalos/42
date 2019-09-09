/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapButtons.js                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:00:21 by amartino          #+#    #+#             */
/*   Updated: 2019/07/01 19:33:08 by ldevelle         ###   ########.fr       */
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

const COLOR_FILL = colors.transparent;
const COLOR_STROKE = colors.secondary_black;
const STROKE_WIDTH = "1";


class MapButtons extends React.Component {


  render() {
    return (
		<View style={{ flex: 1, aspectRatio: 1 }}>
	      <Svg height="100%" width="100%" viewBox="0 0 100 100">
			    <Polygon	//1
			        points="37.3,42.2 37.6,52.3 40.2,55.5 49.5,56.8 50.2,54.0 53.2,46.4"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//2
			        points="38.9,39.1 52.3,32.2 58.2,33.1 53.2,46.4 37.3,42.2"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//3
			        points="53.2,46.4 58.2,33.1 66.6,38.9 70.0,50.4"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//4
			        points="50.2,54.0 53.2,46.4 70.0,50.4 65.9,62.3"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//5
			        points="49.5,56.8 50.2,54.0 65.9,62.3 51.2,72.9 49.2,73.3"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//6
			        points="49.5,56.8 49.2,73.3 36.4,71.6 32.9,69.8 40.2,55.5"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//7
			        points="40.2,55.5 32.9,69.8 22.2,57.2 37.6,52.3"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//8
			        points="37.6,52.3 22.2,57.2 22.5,38.5 26.0,31.5 38.9,39.1 37.3,42.2"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//9
			        points="38.9,39.1 26.0,31.5 38.5,21.0 52.7,18.2 52.3,32.2"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//10
			        points="52.7,18.2 62.1,19.17 79.1,31.5 66.6,38.9 58.2,33.1 52.3,32.2"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//11
			        points="66.6,38.9 79.1,31.5 83.8,53.8 70.0,50.4"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//12
			        points="70.0,50.4 83.8,53.8 96.0,57.0 83.0,80.9 65.9,62.3"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//13
			        points="65.9,62.3 83.0,80.9 52.8,93.1 51.2,72.9"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//14
			        points="51.2,72.9 52.8,93.1 30.5,87.5 36.4,71.6 49.2,73.3"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//15
			        points="36.4,71.6 32.9,69.8 22.2,57.2 12.5,68.8 30.5,87.5"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//16
			        points="22.2,57.2 12.5,68.8 10.3,34.7 22.5,38.5"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//17
			        points="10.3,34.7 31.7,09.4 38.5,21.0 26.0,31.5 22.5,38.5"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//18
			        points="31.7,09.4 66.5,06.6 62.1,19.7 52.7,18.2 38.5,21.0"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//19
			        points="66.5,06.6 90.0,25.0 79.1,31.5 62.1,19.7"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
			    <Polygon	//20
			        points="90.0,25.0 96.0,57.0 83.8,53.8 79.1,31.5"
			        fill={COLOR_FILL}
			        stroke={COLOR_STROKE}
			        strokeWidth={STROKE_WIDTH}
			    />
	      </Svg>
	    </View>
    )
  }
}

export default MapButtons
