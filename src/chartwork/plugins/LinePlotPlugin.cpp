#include <chartwork/plugins/LinePlotPlugin.h>

#include <QtPlugin>

#include <chartwork/LinePlot.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// LinePlotPlugin
//
////////////////////////////////////////////////////////////////////////////////////////////////////

LinePlotPlugin::LinePlotPlugin(QObject *parent)
:	QObject(parent)
{
	m_isInitialized = false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void LinePlotPlugin::initialize(QDesignerFormEditorInterface *)
{
	if (m_isInitialized)
		return;

	m_isInitialized = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

bool LinePlotPlugin::isInitialized() const
{
	return m_isInitialized;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

QWidget *LinePlotPlugin::createWidget(QWidget *parent)
{
	return new chartwork::LinePlot(parent);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

QString LinePlotPlugin::name() const
{
	return "chartwork::LinePlot";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

QString LinePlotPlugin::group() const
{
	return "Chartwork";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

QIcon LinePlotPlugin::icon() const
{
	return QIcon("://icons/icon-line-plot.png");
}

////////////////////////////////////////////////////////////////////////////////////////////////////

QString LinePlotPlugin::toolTip() const
{
	return "";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

QString LinePlotPlugin::whatsThis() const
{
	return "Scatter Plot";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

bool LinePlotPlugin::isContainer() const
{
	return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

QString LinePlotPlugin::domXml() const
{
	return
		("<ui language=\"c++\" displayname=\"LinePlot\">\
			<widget class=\"chartwork::LinePlot\" name=\"linePlot\">\
				<property name=\"geometry\">\
					<rect>\
						<x>0</x>\
						<y>0</y>\
						<width>400</width>\
						<height>300</height>\
					</rect>\
				</property>\
			</widget>\
		</ui>");
}

////////////////////////////////////////////////////////////////////////////////////////////////////

QString	LinePlotPlugin::includeFile() const
{
	return QLatin1String("<chartwork/LinePlot.h>");
}
