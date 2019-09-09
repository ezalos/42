/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubcategoryHeader.js                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:08:15 by ldevelle          #+#    #+#             */
/*   Updated: 2019/07/04 21:25:31 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { StyleSheet, View, Text, FlatList, ActivityIndicator, Image, TouchableOpacity, Shadow, Button } from 'react-native';
import { Container, Spacer, Row, CategoryShortcuts } from './../basic/view.js'
import { Title, Header, Description, IntermediateHeader } from './../basic/text.js'
import {
	colors, borderRadius, fonts, icon, padding, margin, dimensions, fontsSize,
	fontsWeight, fontsFamily, image
} from '../../styles/base.js'

class SubcategoryHeader extends React.Component {

  render () {
		const { subCategoryTitle, displaySubCategory, articles } = this.props
		return (
			<Container>
				<TouchableOpacity
					style={{flex: 1}}
					onPress={() => displaySubCategory(articles, subCategoryTitle)}>
					<IntermediateHeader>{subCategoryTitle}</IntermediateHeader>
				</TouchableOpacity>
			</Container>
		)
  }

}

const styles = StyleSheet.create({})

export default SubcategoryHeader;
