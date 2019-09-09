/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_components.js                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:55:30 by root              #+#    #+#             */
/*   Updated: 2019/05/17 16:40:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

import React from 'react'
import { View, Text, StyleSheet, Image, Dimensions, ScrollView } from 'react-native';
import {colors, fonts, padding, dimensions} from '../../styles/base.js'

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

const styles = StyleSheet.create({
  header: {
    fontFamily: fonts.secondary,
    fontSize: fonts.lg,
    fontWeight: fonts.weight_b,
  },
	main_container: {
		flex: 1,
	},
})

export Container
export Header
