/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.js                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:55:30 by root              #+#    #+#             */
/*   Updated: 2019/07/04 21:28:29 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { View, Text, StyleSheet, Image, Dimensions, ScrollView } from 'react-native';
import { colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize, fontsWeight, fontsFamily } from '../../styles/base.js'
import { buttons, adders, images } from '../../styles/style.js'
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
import { Container, Spacer, Row } from './../basic/view.js'

class Header extends React.Component {
  render() {
   return (
     <Text
       style={ styles.header }
       { ...this.props }
     />
   );
  }
}
class IntermediateHeader extends React.Component {
  render() {
   return (
	   <View style={{flexDirection: 'row', justifyContent: 'flex-start', alignItems: 'center'}}>
		<View style={ [styles.headerButton] }>
		 <Text
	       style={ [styles.intermediateHeader] }
	       { ...this.props }
	     />
	 </View>
	 <Container>
	 <Svg width="30" height="30" viewBox="0 0 24 24" fill="none" stroke="black" stroke-width="1" stroke-linecap="round" stroke-linejoin="round" class="feather feather-arrow-right-circle">
		 <Circle cx="12" cy="12" r="10" strokeWidth="1.5"></Circle>
		 <Polyline points="12 16 16 12 12 8" strokeWidth="1.5"></Polyline>
		 <Line x1="8" y1="12" x2="16" y2="12" strokeWidth="1.5"></Line>
 	</Svg>
	</Container>
	 </View>
   );
  }
}

class Title extends React.Component {
  render() {
   return (
     <Text
       style={ styles.title }
       { ...this.props }
     />
   );
  }
}

class MainHeader extends React.Component {
  render() {
   return (
	 <View style={ [styles.bottomLine, adders.shadow] }>
	     <Text
	       style={ [styles.mainHeader] }
	       { ...this.props }
	     />
	 </View>
   );
  }
}

class ParHeader extends React.Component {
  render() {
   return (
	 <View style={ [styles.bottomLine, adders.shadow] }>
	     <Text
	       style={ [styles.mainHeader, {fontFamily: fontsFamily.paridylle}] }
	       { ...this.props }
	     />
	 </View>
   );
  }
}

class Description extends React.Component {
  render() {
   return (
     <Text
       style={ styles.title }
       { ...this.props }
     />
   );
  }
}

const styles = StyleSheet.create({
  header: {
    fontFamily: fontsFamily.paridylle,
    fontSize: fontsSize.xxl,
    fontWeight: fontsWeight.bold,
	color: colors.primary_black,
	paddingTop: padding.sm,
	alignSelf: 'center',
  },
  headerButton: {
	  marginHorizontal: margin.xl,
	  marginTop: margin.lg,
	  marginBottom: margin.xl,
  },
	intermediateHeader: {
		fontSize: fontsSize.xl,
		fontWeight: fontsWeight.bold,
		color: colors.primary_black,
		alignSelf: 'center',
	},
	mainHeader: {
		fontSize: fontsSize.xxl,
		fontWeight: fontsWeight.bold,
		color: colors.primary_black,
		padding: padding.sm,
		alignSelf: 'center',
	},
  title: {
    fontFamily: fontsFamily.secondary,
    fontSize: fontsSize.xl,
    fontWeight: fontsWeight.bold,
		color: colors.primary_black,
  },
bottomLine: {
	borderBottomColor: colors.line,
	borderBottomWidth: 1,
	backgroundColor: colors.primary_white,
},
  description: {
    fontFamily: fontsFamily.secondary,
    fontSize: fontsSize.sm,
    fontWeight: fontsWeight.normal,
	color: colors.secondary_black,
  },
})

export { Title, Header, Description, MainHeader, ParHeader, IntermediateHeader }
// import { Title, Header, Description } from './../basic/text.js'
