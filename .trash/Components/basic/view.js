/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.js                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:55:30 by root              #+#    #+#             */
/*   Updated: 2019/07/02 21:01:43 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { View, Text, StyleSheet, Image, Dimensions, ScrollView } from 'react-native';
import { colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize, fontsWeight, fontsFamily } from '../../styles/base.js'
import { buttons, adders } from '../../styles/style.js'
import HomeIcon from '../Home/HomeIcon'

class Container extends React.Component {
	render() {
		return (
      <View
        style={ styles.main_container }
        { ...this.props }
      />
		)
  }
}

class Spacer extends React.Component {
  render() {
   return (
     <View
		 		style={ styles.spacer }
       { ...this.props }
     />
   )
  }
}

class Row extends React.Component {
  render() {
   return (
     <View
			style={[styles.row]}
       { ...this.props }
     />
   );
  }
}

class WrapRow extends React.Component {
  render() {
   return (
     <View
			style={[styles.wrapRow]}
       { ...this.props }
     />
   );
  }
}

class RowSA extends React.Component {
  render() {
   return (
     <View style={[styles.rowSA]}
       { ...this.props }
     />
   );
  }
}

class ArticleBox extends React.Component {
  render() {
   return (
		 <View style={[styles.articleBox, adders.shadow]}>
     <View
			style={[styles.articleBoxMargin]}
       { ...this.props }
     />
		 </View>
   );
  }
}

class AdditionalInfo extends React.Component {
  render() {
   return (
     <View
			style={[styles.additionalInfo]}
       { ...this.props }
     />
   );
  }
}

class CategoryShortcuts extends React.Component {

  render() {
		const { intermediateCategoryAccess } = this.props
   return (
		 <Row>
			 <HomeIcon
				 img={require("../../assets/good/ParAppetit.png")}
				 categoryTitle={"Par'Appetit"}
				 categoryAccess={intermediateCategoryAccess}
			 />
			 <View style={styles.space}/>
			 <HomeIcon
				 img={require("../../assets/good/ParIvresse.png")}
				 categoryTitle={"Par'Ivresse"}
				 categoryAccess={intermediateCategoryAccess}
				 color={'#FF00FF'}
			 />
			 <View style={styles.space}/>
			 <HomeIcon
				 img={require("../../assets/good/ParAilleurs.png")}
				 categoryTitle={"Par'Ailleurs"}
				 categoryAccess={intermediateCategoryAccess}
			 />
			 <View style={styles.space}/>
			 <HomeIcon
				 img={require("../../assets/good/ParPassion.png")}
				 categoryTitle={"Par'Passion"}
				 categoryAccess={intermediateCategoryAccess}
				 color={'#FF00FF'}
			 />
			 <View style={styles.space}/>
			 <HomeIcon
				 img={require("../../assets/good/ParGourmandise.png")}
				 categoryTitle={"Par'Gourmandise"}
				 categoryAccess={intermediateCategoryAccess}
				 color={'#FF00FF'}
			 />
		 </Row>
   );
  }
}

const styles = StyleSheet.create({
	spacer: {
		flex: 1,
	},
	main_container: {
		flex: 1,
	},
  articleBox: {
    margin: 10,
		backgroundColor: colors.primary_white,
		flex: 1,
		elevation: 3,
		borderRadius:borderRadius.md,
    justifyContent: 'center',
  },
	articleBoxMargin: {
		margin: 10,
	},
	row: {
		flexDirection: 'row',
		justifyContent: 'space-between',
		margin: margin.md,
	},
	wrapRow: {
		flexDirection: 'row',
		flexWrap: 'wrap',
		justifyContent: 'space-between',
	},
	rowSA: {
		flexDirection: 'row',
		justifyContent: 'space-between',
		alignItems: 'center',
		marginVertical: margin.md,
	},
	shadow: {
		shadowOpacity:1,
		elevation: 3,
    	shadowRadius: 5,
    	shadowOffset: { x: 2, y: -2 },
		shadowColor: colors.primary_black,
		backgroundColor: colors.primary_black,
	},
  additionalInfo: {
		backgroundColor: colors.primary_white,
		backgroundColor: 'rgba(240,240,240,0.5)',
		height: undefined,
		width: undefined,
		alignSelf: 'center',
		borderRadius:borderRadius.md,
		margin: margin.md,
		borderColor: 'rgba(240,240,240,1)',
		borderWidth: 3,
    	justifyContent: 'center',
		flexWrap: 'wrap',
		flexDirection: 'row',
		justifyContent: 'flex-start',
		alignItems: 'center',
		margin: margin.sm,
	},
})

export { Container, Spacer, Row, CategoryShortcuts, RowSA, AdditionalInfo, WrapRow, ArticleBox }
// import { Container, Spacer, Row } from './../basic/view.js'
